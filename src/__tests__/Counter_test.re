open Jest;

describe("Counter", () => {
    open Expect;
    open! Expect.Operators;

    test("add", () =>
      expect(Counter.add(1, 2)) === 3)

    test("increase", () => {
      expect(1 + 1) === 2;
    });
  }
);