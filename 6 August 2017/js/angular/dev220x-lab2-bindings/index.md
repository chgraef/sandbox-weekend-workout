HTML Code snippet:

```
<div class="container" ng-app="my-app">
  <div class="menu" ng-controller="menu-controller">
    <h1>Title</h1>
    <h2>Menu</h2>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('A', '0.00')" />
        A
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('B', '0.00')" />
        B
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('C', '0.00')"/>
        C
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('D', '0.00')"/>
        D
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('E', '0.00')"/>
        E
      </label>
    </div>
    <h3>Selected Item</h3>
    <pre>{{selection.name || 'Your Selection'}}</pre>
    <h3>Special Instructions</h3>
    <textarea ng-model="instructions.content"></textarea>
    <h3>Your Order</h3>
    <div>{{selection.name}} {{'$' + selection.price}} {{instructions.content}}</div>
  </div>
</div>
```
