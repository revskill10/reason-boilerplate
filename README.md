# ReasonML Boilerplate

## What buys you here ?

- ReasonML plus React in a project
- Hot reloading both client, server and tests
- Jest testing
- Sensible EventStore for pure store mutation
- Server side rendering

## Examples:

- Testing a component:

```
open Jest;

describe("Counter", () => {
  open Expect;
  open! Expect.Operators;

  test("add", () =>
    expect(Counter.add(1, 2)) === 3)

  test("increase", () => {
    expect(1 + 1) === 2;
  });

  test("component", () => {
    let store: Store.store = {
      state: { counter: { count: 1 } } ,
      publish: (_event) => ()
    };
    let wrapper = Enzyme.shallow(<Counter store />);
    let expectedNode = <h1>(ReasonReact.string("Hello"))</h1>;
    expect(Enzyme.contains(expectedNode, wrapper)) |> toBe(true)
  });
});
```

## Development:

```
yarn start:client
yarn start:server
yarn test
```
