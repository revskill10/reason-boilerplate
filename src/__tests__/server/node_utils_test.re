open Jest;


describe("NodeApi", () => {
  open Expect;

  test("readFileSync", () => {
    let url = "build/index.html";
    let expected = Node.Fs.readFileSync(url, `utf8); 
    expect(expected) |> toContainString("<!doctype html>");
  });
});