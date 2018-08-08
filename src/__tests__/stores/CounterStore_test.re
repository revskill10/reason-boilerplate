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

  test("cont", () => {
    let human = (arguments, next): string => "human" ++ arguments ++ " {" ++ next ++ " }";
    let args = (arr: array(string)): string => {
      let lst = Array.to_list(arr);
      let tmp = List.fold_left((a, b) => a ++ "," ++ b, List.hd(lst), List.tl(lst));
      "(" ++ tmp ++ ")";
    };
    let id = (x: int): string => "id: \"" ++ string_of_int(x) ++ "\"";
    let name : string = "name";
    let height: string = "height";
    let return = (arr: array(string)): string => Array.fold_left((a, b) => a ++ " " ++ b, "", arr);
    expect(human(args([|id(1000)|]), return([|name, height|]))) |> toEqual("human(id: \"1000\") { name height }")
  });
});