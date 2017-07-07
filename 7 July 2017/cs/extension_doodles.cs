using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CshConsoleApplication8
{
    static class Extensions
    {
        public static void Shuffle(this Array ary)
        {
            if (ary == null) {
                throw new NullReferenceException("ary");
            }

            var generator = new Random();
            
            for (Int32 index = 0; index < ary.Length; ++index) 
            {
                Int32 randomIndex = generator.Next(0, 1 + index);

                var randomValue   = ary.GetValue(randomIndex);
                var currentValue  = ary.GetValue(index);

                ary.SetValue(randomValue, index);
                ary.SetValue(currentValue, randomIndex);
            }
        }

        public static bool IsInOrder(this Array ary, IComparer<Object> comparer = null)
        {
            if (ary == null) {
                throw new NullReferenceException("ary");
            }
            
            comparer = comparer ?? Comparer<Object>.Default;

            for (Int32 index = 0; index + 1 < ary.Length; ++index) 
            {
                var leftValue  = ary.GetValue(index);
                var rightValue = ary.GetValue(index + 1);
                
                if (comparer.Compare(leftValue, rightValue) > 0) {
                    return false;
                }
            }

            return true;
        }

        public static T[] Shrink<T>(this IEnumerable<T> ary, Int32 newSize)
        {
            if (ary == null) {
                throw new NullReferenceException("ary");
            }
            
            return ary.Take(newSize).ToArray();
        }

        public static T[] Shrink<T>(this IEnumerable<T> ary, Func<T, Boolean> condition = null)
        {
            if (ary == null) {
                throw new NullReferenceException("ary");
            }

            condition = condition ?? ((x) => x != null);
            
            return ary.TakeWhile(condition).ToArray();
        }

        public static T[] Copy<T>(this IEnumerable<T> ary)
        {
            if (ary == null) {
                throw new NullReferenceException("ary");
            }

            return ary.Select((x) => x).ToArray();
        }

        public static T[] Sort<T>(this IEnumerable<T> ary, IComparer<T> comparer = null)
        {
            if (ary == null) {
                throw new NullReferenceException("ary");
            }

            comparer = comparer ?? Comparer<T>.Default;

            return ary.OrderBy((x) => x, comparer).ToArray();
        }
    }

    class Program
    {
        //// Easy Mode ON
        //static private String[] RemoveDuplicatesAndSort(String[] strings)
        //{
        //    if (strings == null) {
        //        throw new NullReferenceException("strings");
        //    }

        //    return new HashSet<String>(strings).OrderBy((x) => x).ToArray();
        //}

        static private String[] RemoveDuplicatesAndSort(String[] strings)
        {
            if (strings == null) {
                throw new NullReferenceException("strings");
            }

            var   stringsCopy = new String[strings.Length];
            Int32 newSize     = 0;

            Array.Copy(strings, stringsCopy, strings.Length);
            RemoveDuplicatesAndSortDestructively(stringsCopy, out newSize);

            var buffer = new String[newSize];

            Array.Copy(stringsCopy, buffer, newSize);
        
            return buffer;
        }

        static private void RemoveDuplicatesAndSortDestructively(String[] strings, out Int32 newSize)
        {
            if (strings == null) {
                throw new NullReferenceException("strings");
            }

            Array.Sort(strings);

            Int32 slow = 0;
            Int32 fast = 0;

            while (fast < strings.Length)
            {
                if (strings[slow] != strings[fast]) 
                {
                    ++slow;
                    strings[slow] = strings[fast];
                }

                ++fast;
            }

            newSize = 1 + slow;
        }

        static void Main(String[] args)
        {
            //var duplicateStrings = new String[] {
            //    "Marines", "Coralis", "Coralis", "Coralis", "Marines",
            //    "Germanicus", "Caligula", "Caligula"
            //};

            //duplicateStrings.Shuffle();

            //var uniqueStrings = RemoveDuplicatesAndSort(duplicateStrings);

            //Console.WriteLine(String.Join(" ", duplicateStrings));
            //Console.WriteLine(duplicateStrings.IsInOrder());

            //Console.WriteLine(String.Join(" ", uniqueStrings));
            //Console.WriteLine(uniqueStrings.IsInOrder());

            var words = new String[] { 
                "Augustus", "Claudius", "Caligula", "Nero", "Pompey",
                null, null, null, null
            };

            var shrinked = words.Shrink().Sort();

            Action<Object[]> printWithNull = (ary) => 
            {
                foreach (var item in ary) {
                    Console.Write("{0} ", item ?? "null");
                }
            
                Console.WriteLine();
            };

            printWithNull(shrinked);
            printWithNull(words);
        }
    }
}
