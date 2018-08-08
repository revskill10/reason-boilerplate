# ReasonML Boilerplate

> Production code should be unit tested and type-safe.

> Production code should be functional: easy for testing, easily portable between implementations, easy to reason.

## What buys you here ?

- ReasonML plus React in a project
- Hot reloading both client, server and tests, config and git branchs
- Jest testing
- Sensible EventStore for pure store mutation
- Server side rendering
- Code coverage on every save

## What is this Universal Application ?

- Maximize Code reuse for every type of application, regardless web, server, mobile
- Best user experience as possible: Fast server-side rendering on initial loading, interactive user interface with Javascript.
- Standing on giants' shoulders with ecosystem from Ocamls, Javascript and ReasonML.
- Focus on writing functional codes, let alone configuration, building, testing for the boilerplate.

## Examples:

- Testing a component:

```ocaml
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

- Testing Promise

```ocaml
open Jest;

describe("GraphQL", () => {
  open Expect;


  testPromise("UserQuery", () => {
    let userQuery = GraphQL.UserQuery.make();
    let sampleResponse = "{ \"users\": [
      {
        \"email\": \"sampleuser@gmail.com\",
        \"password\": \"samplepassword\"
      }
    ] }";
    
    let expected = Js.Json.parseExn(sampleResponse) |> userQuery##parse;

    let assertion = result => expect(result) |> toEqual(expected);

    userQuery
    |> Api.sendQuery 
    |> Js.Promise.(then_(result => resolve(assertion(result))));
  });
});

```

## Development:

```
yarn send-introspection-query http://localhost:8081/v1alpha1/graphql -H "X-Hasura-Access-Key:mysecretkey"

yarn start:client

yarn start:server

yarn test
```
## Todos:

- Multiple entries for each server-side routes.
- Reuse event store between server and client

## Materials for deep references:

- [FFI with ReasonML and Javascript](https://medium.com/@davidgomes/exploring-bucklescripts-interop-with-javascript-in-reason-a00ad3e6d81b)