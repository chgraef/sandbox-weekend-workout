class StateStack:
    def __init__(self, current_state):
        self._states = [current_state]
        self._index  = 0

    def append_state(self, state):
        if self._index + 1 >= len(self._states):
            self._states.append(state)
        else:
            self._states[self._index + 1] = state
        self._index += 1

    def current_state(self):
        return self._states[self._index]

    def undo(self, times=1):
        undone_index = max(self._index - times, 0)
        undone_state = self._states[undone_index]
        self._index  = undone_index

        return undone_state

    def redo(self, times=1):
        redone_index = min(self._index + times, len(self._states) - 1)
        redone_state = self._states[redone_index]
        self._index  = redone_index

        return redone_state

class CalculatorState:
    def __init__(self, value):
        self._value = value

    def value(self):
        return self._value

class Calculator:
    def __init__(self, value=0):
        current_state = CalculatorState(value)
        self._states  = StateStack(current_state)

    def add(self, value):
        current_value = self.value()
        result        = current_value + value
        new_state     = CalculatorState(result)
        
        self._states.append_state(new_state)

    def value(self):
        current_state = self._states.current_state()
        current_value = current_state.value()
        
        return current_value

    def undo(self, times=1):
        self._states.undo(times)

    def redo(self, times=1):
        self._states.redo(times)

    def __str__(self):
        value = self.value()
        return str(value)

calculator = Calculator()

while True:
    try:
        print('>>>', end=' ')
        user_input = input()

        if user_input.isdigit():
            value = int(user_input)
            calculator.add(value)
        elif user_input.startswith('u'):
            calculator.undo()
        elif user_input.startswith('r'):
            calculator.redo()
        else:
            raise Exception('Input invalid.')

        print(calculator)
    except Exception as e:
        print(e)
