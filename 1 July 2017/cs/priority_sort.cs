using System;
using System.Collections.Generic;
using System.Linq;

namespace CshConsoleApplication7
{
    class Program
    {
        private static IEnumerable<TItem> PrioritySort<TItem>(
            IEnumerable<TItem> values, TItem[] priorities
        )
        {
            var lowestPriority = priorities.Length;
            var priorityLookup = new Dictionary<TItem, Int32>();
            
            for (var priority = 0; priority < priorities.Length; ++priority) {
                var item = priorities[priority];
                priorityLookup.Add(item, priority);
            }
            
            return 
                values.OrderBy((item) => {
                    if (priorityLookup.ContainsKey(item)) {
                        return priorityLookup[item];
                    } else {
                        return lowestPriority;
                    }
                }).ThenBy((x) => x).AsEnumerable();
        }

        static void Main(string[] args)
        {
            var priorities   = new String[] { "mango", "banana" };
            var greenBasket  = new String[] { "orange", "banana", "tomato", 
                                              "passionfruit", "mango", "mango" };

            var sortedBasket = PrioritySort(greenBasket, priorities);

            Console.WriteLine(String.Join(" ", sortedBasket));
        }
    }
}
