let app = angular.module('my-app', []);

app.controller('my-controller', [
  '$scope', 
  ($scope) => {
    $scope.textarea = {};
  }
]);

