open Jest;

describe("Template", () => {
  open Expect;

  test("make", () => {
    let title = "Hello World"
    let content = <Store 
      render=(store => 
        <div>
          (<Counter store />)
        </div>)
    />
    |> ReactDOMServerRe.renderToString
    |> Template.make(~title, ());
    expect(content) |> toContainString(title);
  });

  test("Helper.add", () => {
    expect(Template.Helper.add(1,2)) |> toEqual(3);
  });
});
