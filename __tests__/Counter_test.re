open Jest;
open Counter;

describe("Expect.Operators", () => {
    open Expect;
    open! Expect.Operators;

    test("==", () =>
      expect(1 + 2) === 3)
  }
);