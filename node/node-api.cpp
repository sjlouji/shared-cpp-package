#include <node_api.h>
#include <vector>
#include "rate_calculator/rate_calculator.h"

#define NAPI_CALL(env, call)                                      \
  do                                                              \
  {                                                               \
    napi_status status = (call);                                  \
    if (status != napi_ok)                                        \
    {                                                             \
      const napi_extended_error_info *error_info = NULL;          \
      napi_get_last_error_info((env), &error_info);               \
      bool is_pending;                                            \
      napi_is_exception_pending((env), &is_pending);              \
      if (!is_pending)                                            \
      {                                                           \
        const char *message = (error_info->error_message == NULL) \
                                  ? "empty error message"         \
                                  : error_info->error_message;    \
        napi_throw_error((env), NULL, message);                   \
        return NULL;                                              \
      }                                                           \
    }                                                             \
  } while (0)

napi_value CalculateRate(napi_env env, napi_callback_info info) {
    size_t argc = 1;
    napi_value args[1];
    napi_status status;
    uint32_t length;
    double rate;

    NAPI_CALL(env, napi_get_cb_info(env, info, &argc, args, NULL, NULL));

    napi_valuetype type;
    NAPI_CALL(env, napi_typeof(env, args[0], &type));
    if (type != napi_object) {
        napi_throw_type_error(env, NULL, "Argument must be an array");
        return NULL;
    }

    NAPI_CALL(env, napi_get_array_length(env, args[0], &length));

    std::vector<double> contracts(length);

    for (uint32_t i = 0; i < length; ++i) {
        napi_value element;
        NAPI_CALL(env, napi_get_element(env, args[0], i, &element));

        double value;
        NAPI_CALL(env, napi_get_value_double(env, element, &value));
        contracts[i] = value;
    }

    rate = calculate_rate(contracts);

    napi_value result;
    NAPI_CALL(env, napi_create_double(env, rate, &result));

    return result;
}

napi_value Init(napi_env env, napi_value exports) {
    napi_value calculate_rate_fn;
    napi_status status;

    status = napi_create_function(env, NULL, 0, CalculateRate, NULL, &calculate_rate_fn);
    if (status != napi_ok) return NULL;
    
    status = napi_set_named_property(env, exports, "calculateRate", calculate_rate_fn);
    if (status != napi_ok) return NULL;

    return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init)