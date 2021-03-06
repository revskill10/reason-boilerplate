/* make the express app */
let app = Express.App.make();

Express.Static.defaultOptions()
|> Express.Static.make("build/static")
|> Express.Static.asMiddleware
|> Express.App.useOnPath(app, ~path="/assets");

/* Our initial rendering function, we will soon make this way better */
let renderHTML = (_next, _req, res) => {
  let content = <Store 
      render=(store => 
        <div>
          (<Counter store />)
        </div>)
    />
    |> ReactDOMServerRe.renderToString
    |> Template.make(~title="Test", ());
  Express.Response.sendString(content, res);
};

/* Express works on middleware and bs-express provides an easy way to make
   middleware out of functions */
renderHTML
|> Express.Middleware.from
|> Express.App.useOnPath(~path="/", app);

let port = 3001;

/* Getting a nice message when the server starts */
let onListen = e =>
  switch e {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log("listening at localhost:" ++ string_of_int(port))
  };

/* starting up the express app */
Express.App.listen(app, ~onListen, ~port, ());