let app = angular.module('my-app', []);

app.controller('menu-controller', [
  '$scope',
  ($scope) => {
    class Selection {
      select(name, price) {
        this.name  = name;
        this.price = price;
      }
    }
  
    $scope.selection = new Selection();

    $scope.select = (item, price) => {
      $scope.selection.select(item, price);
    }

    $scope.$watch('selection.selection.name', 
      (newValue, oldValue) => {
        if (newValue) {
          alert("You have selected " + newValue);
        }
      }
    );

    $scope.instructions = { };
  }
]);
