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

public func factorial(x: Int) -> Int {
    if x <= 0 {
        return 1
    }
    return x * factorial(x: x - 1)
}

public func hello() {
    print("Hello, world!")
}
