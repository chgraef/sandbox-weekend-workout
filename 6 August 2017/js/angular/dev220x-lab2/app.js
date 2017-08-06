let app = angular.module('my-app', []);

app.controller('menu-controller', [
  '$scope',
  ($scope) => {
    class Selection {
      select(item) {
        this.selection = item;
      }
      
      toString() {
        return this.selection || 'Your Selection';
      }
    }
    
    $scope.selection = new Selection();
    
    $scope.select = (item) => {
      $scope.selection.select(item);
    }
    
    $scope.$watch('selection.selection', 
      (newValue, oldValue) => {
        if (newValue) {
          alert("You have selected " + newValue);
        }
      }
    );
  }
]);
