using System;
using System.Linq;
using System.Collections.Generic;

using NUnit.Framework;
using NUnit.Framework.Internal;

namespace CshConsoleApplication4
{
    class Program
    {
        [TestFixture]
        private sealed class AreUniquelyEqualTest
        {
            private String OutputMessageFormat    => "Left: {0}\nRight: {1}\n";
            private String OutputSeparatorFormat  => " ";

            private String EnumerableToString<T>(IEnumerable<T> enumer) =>
                String.Join(OutputSeparatorFormat, enumer);

            private void RunTruthyTest(Int32[] left, Int32[] right)
            {
                String leftStr  = EnumerableToString(left);
                String rightStr = EnumerableToString(right);

                Assert.IsTrue(AreUniquelyEqual(left, right), 
                              OutputMessageFormat, leftStr, rightStr);
            }

            private void RunFalsyTest(Int32[] left, Int32[] right)
            {
                String leftStr  = EnumerableToString(left);
                String rightStr = EnumerableToString(right);

                Assert.IsFalse(AreUniquelyEqual(left, right),
                               OutputMessageFormat, leftStr, rightStr);
            }

            [Test]
            [Description("Both array-arguments initially equal.")]
            public void AreUniquelyEqual_00()
            {
                Int32[] left  = { 0, 1, 2, 3 };
                Int32[] right = { 0, 1, 2, 3 };

                RunTruthyTest(left, right);
            }

            [Test]
            [Description("Both array-arguments initially uniquely equal.")]
            public void AreUniquelyEqual_01()
            {
                Int32[] left  = { 1, 1, 1, 1 };
                Int32[] right = { 1 };

                RunTruthyTest(left, right);
            }

            [Test]
            [Description("Both array-arguments initially uniquely equal.")]
            public void AreUniquelyEqual_02()
            {
                Int32[] left  = { 1 };
                Int32[] right = { 1, 1, 1, 1 };

                RunTruthyTest(left, right);
            }

            [Test]
            [Description("Both array-arguments initially uniquely equal.")]
            public void AreUniquelyEqual_03()
            {
                Int32[] left  = { 1, 2, 1, 1 };
                Int32[] right = { 1, 2, 2, 2 };

                RunTruthyTest(left, right);
            }

            [Test]
            [Description("Both array-arguments initially uniquely not equal.")]
            public void AreUniquelyEqual_04()
            {
                Int32[] left  = { 1, 2, 1, 1 };
                Int32[] right = { 1, 2, 5, 2 };

                RunFalsyTest(left, right);
            }

            [Test]
            [Description("Both array-arguments initially uniquely not equal.")]
            public void AreUniquelyEqual_05()
            {
                Int32[] left  = { 1, 2, 5, 1 };
                Int32[] right = { 1, 2, 1, 2 };

                RunFalsyTest(left, right);
            }

            public static void RunAllTests()
            {
                var fixture = new AreUniquelyEqualTest();
                var tests   = from   method in fixture.GetType().GetMethods()
                              where  method.Name.StartsWith("AreUniquelyEqual")
                              select method;

                foreach (var method in tests) {
                    method.Invoke(fixture, null);
                }
            }
        }

        private static Int32[] RemoveDuplicates(Int32[] ary)
        {
            if (ary == null) throw new ArgumentNullException("ary");

            var   sorted = ary.OrderBy((x) => x).ToArray();
            Int32 slow   = 0;
            Int32 fast   = 0;

            while (fast < sorted.Length) 
            {
                if (sorted[slow] != sorted[fast]) 
                {
                    ++slow;
                    sorted[slow] = sorted[fast];
                }

                ++fast;
            }

            return sorted.Take(slow + 1).ToArray();
        }

        private static Boolean AreUniquelyEqual(Int32[] left, Int32[] right)
        {
            if (left  == null) throw new ArgumentNullException("left");
            if (right == null) throw new ArgumentNullException("right");

            var sortedLeft  = left.OrderBy((x) => x).ToArray();
            var sortedRight = right.OrderBy((x) => x).ToArray();
            
            var uniqLeft  = RemoveDuplicates(sortedLeft);
            var uniqRight = RemoveDuplicates(sortedRight);

            return uniqLeft.SequenceEqual(uniqRight);
        }

        static void Main(string[] args)
        {
            AreUniquelyEqualTest.RunAllTests();
        }
    }
}
