open Jest;


describe("CounterStore", () => {
  open Expect;
  open! Expect.Operators;
  open CounterStore;  

  test("fold", () => {
    let state : state = { count : 1 };
    let expectedState : state = { count: 2 };
    expect(fold(Increased, state)) |> toEqual(expectedState);
  });
  }
);