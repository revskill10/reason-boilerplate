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
