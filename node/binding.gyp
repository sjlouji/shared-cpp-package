{
  "targets": [
    {
      "target_name": "fft",
      "sources": [
        "node-api.cpp",
        "rate_calculator/rate_calculator.cpp"
      ],
      "include_dirs": [
        "<!(node -p \"require('node-addon-api').include\")"
      ],
      "cxxflags": [
        "-std=c++11"
      ]
    }
  ]
}