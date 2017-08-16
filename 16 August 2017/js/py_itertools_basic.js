function* count(start = 0)
{
    for (; ;) yield start++;
}

function* cycle(iterable)
{
    for (; ;) {
        for (value of iterable) {
            yield value;
        }
    }
}

function* range(start, stop, step = 1)
{
    let value = start;

    for (let value = start; value < stop; value += step) {
        yield value;
    }
}

function* repeat(value, times)
{
    let iter = times !== undefined ?
        range(0, times) : count();

    for (let _temp of iter) {
        yield value;
    }
}

function* dropwhile(pred, iterable)
{
    let canYieldThis = false;

    for (let value of iterable)
    {
        if (!canYieldThis) canYieldThis = !pred(value);
        if (canYieldThis)  yield value;    
    }
}

function* takewhile(pred, iterable)
{
    let canYieldThis = true;

    for (let value of iterable)
    {
        if (canYieldThis) canYieldThis = pred(value);
        if (canYieldThis) yield value;
    }
}

function* chain()
{
    const iterables = arguments;

    for (let iterable of iterables) {
        for (let value of iterable) {
            yield value;
        }
    }
}

function* zip()
{
    const iterables = Object.keys(arguments).map((x) => arguments[x]);
    const iterators = iterables.map((x) => x[Symbol.iterator]());

    for (; ;) {
        const iterData = iterators.map((x) => x.next());

        if (iterData.find((x) => x.done)) break;

        const values = iterData.map((x) => x.value);
        yield values;
    }
}

/* Matrix transposition example. */

const matrix = [[0, 1, 2],
                [3, 4, 5],
                [6, 7, 8]];

const transposed = [...zip(...matrix)];

console.log(transposed);

