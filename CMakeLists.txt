cmake_minimum_required(VERSION 3.29)
project(AS6)

set(CMAKE_CXX_STANDARD 14)

add_executable(AS6
    main.cpp
        "OutputClassHeader().cpp"
        "ValidateSex().cpp"
        "CheckMeasuremnt().cpp"
        "ValidateIntInput().cpp"
        "EvaluateCandidate().cpp")
