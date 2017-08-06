HTML Code snippet:

```
<div class="container"
   ng-app="my-app"
   ng-controller="my-controller">
  <div>
    <label>Your input, please</label>
    <textarea ng-model="textarea.content"></textarea>
  </div>
  <div>
    <label>Your input (not sanitized) was:</label>
    <p>{{textarea.content}}</p>
  </div>
</div>
```
