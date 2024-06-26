//===----------------------------------------------------------------------===//
//
// This source file is part of the Swift open source project
//
// Copyright (c) 2023 Apple Inc. and the Swift project authors.
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
//
//===----------------------------------------------------------------------===//

#include "fibonacci/fibonacci-swift.h"
#include "fibonacci/fibonacci.h"
#include <iostream>

int main(int argc, char ** argv) {
  std::cout << fibonacci_cpp(5) << std::endl;
  std::cout << SwiftFibonacci::fibonacciSwift(5) << std::endl;
  return 0;
}
