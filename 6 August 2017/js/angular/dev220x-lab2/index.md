HTML Code snippet:
```
<div class="container" ng-app="my-app">
  <div class="menu" ng-controller="menu-controller">
    <h1>Title</h1>
    <h2>Menu</h2>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('A')" />
        A
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('B')" />
        B
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('C')"/>
        C
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('D')"/>
        D
      </label>
    </div>
    <div>
      <label>
        <input type="radio" name="menu-category" ng-click="select('E')"/>
        E
      </label>
    </div>
    <h3>Selected Item</h3>
    <pre>{{selection}}</pre>
  </div>
</div>
```
