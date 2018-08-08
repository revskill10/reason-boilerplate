[@bs.module "../registerServiceWorker"]
external register_service_worker : unit => unit = "default";

ReactDOMRe.renderToElementWithId(
  <Store 
    render=(store => 
      <div>
        (<Counter store />)
      </div>
    ) 
  />,
  "root",
);

register_service_worker();
