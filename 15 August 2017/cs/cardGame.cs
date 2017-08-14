using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CshConsoleApplication1
{
    public sealed class Program
    {
        class Card
        {
            public enum Suite
            {
                Diamonds,
                Clubs,
                Spades,
                Hearts
            }

            public enum Value
            {
                Ace   = 1,
                Two   = 2,
                Three = 3,
                Four  = 4,
                Five  = 5,
                Six   = 6,
                Seven = 7,
                Eight = 8,
                Nine  = 9,
                Ten   = 10,
                Jack  = 11,
                Queen = 12,
                King  = 13,
            }

            private Suite _suite;
            private Value _value;

            private Card(Suite suite, Value value)
            {
                CurrentSuite = suite;
                CurrentValue = value;
            }

            public override string ToString() =>
                String.Format("{0} of {1}", CurrentValue, CurrentSuite);

            public Suite CurrentSuite {
                get => _suite;
                private set { _suite = value; } 
            }

            public Value CurrentValue {
                get => _value;
                private set { _value = value; }
            }

            public static Card AceOfSpades   { get => new Card(Suite.Spades, Value.Ace); }
            public static Card KingOfSpades  { get => new Card(Suite.Spades, Value.King); }
            public static Card QueenOfSpades { get => new Card(Suite.Spades, Value.Queen); }
            public static Card JackOfSpades  { get => new Card(Suite.Spades, Value.Jack); }
            public static Card TenOfSpades   { get => new Card(Suite.Spades, Value.Ten); }
            public static Card NineOfSpades  { get => new Card(Suite.Spades, Value.Nine); }
            public static Card EightOfSpades { get => new Card(Suite.Spades, Value.Eight); }
            public static Card SevenOfSpades { get => new Card(Suite.Spades, Value.Seven); }
            public static Card SixOfSpades   { get => new Card(Suite.Spades, Value.Six); }
            public static Card FiveOfSpades  { get => new Card(Suite.Spades, Value.Five); }
            public static Card FourOfSpades  { get => new Card(Suite.Spades, Value.Four); }
            public static Card ThreeOfSpades { get => new Card(Suite.Spades, Value.Three); }
            public static Card TwoOfSpades   { get => new Card(Suite.Spades, Value.Two); }

            public static Card AceOfHearts   { get => new Card(Suite.Hearts, Value.Ace); }
            public static Card KingOfHearts  { get => new Card(Suite.Hearts, Value.King); }
            public static Card QueenOfHearts { get => new Card(Suite.Hearts, Value.Queen); }
            public static Card JackOfHearts  { get => new Card(Suite.Hearts, Value.Jack); }
            public static Card TenOfHearts   { get => new Card(Suite.Hearts, Value.Ten); }
            public static Card NineOfHearts  { get => new Card(Suite.Hearts, Value.Nine); }
            public static Card EightOfHearts { get => new Card(Suite.Hearts, Value.Eight); }
            public static Card SevenOfHearts { get => new Card(Suite.Hearts, Value.Seven); }
            public static Card SixOfHearts   { get => new Card(Suite.Hearts, Value.Six); }
            public static Card FiveOfHearts  { get => new Card(Suite.Hearts, Value.Five); }
            public static Card FourOfHearts  { get => new Card(Suite.Hearts, Value.Four); }
            public static Card ThreeOfHearts { get => new Card(Suite.Hearts, Value.Three); }
            public static Card TwoOfHearts   { get => new Card(Suite.Hearts, Value.Two); }

            public static Card AceOfClubs   { get => new Card(Suite.Clubs, Value.Ace); }
            public static Card KingOfClubs  { get => new Card(Suite.Clubs, Value.King); }
            public static Card QueenOfClubs { get => new Card(Suite.Clubs, Value.Queen); }
            public static Card JackOfClubs  { get => new Card(Suite.Clubs, Value.Jack); }
            public static Card TenOfClubs   { get => new Card(Suite.Clubs, Value.Ten); }
            public static Card NineOfClubs  { get => new Card(Suite.Clubs, Value.Nine); }
            public static Card EightOfClubs { get => new Card(Suite.Clubs, Value.Eight); }
            public static Card SevenOfClubs { get => new Card(Suite.Clubs, Value.Seven); }
            public static Card SixOfClubs   { get => new Card(Suite.Clubs, Value.Six); }
            public static Card FiveOfClubs  { get => new Card(Suite.Clubs, Value.Five); }
            public static Card FourOfClubs  { get => new Card(Suite.Clubs, Value.Four); }
            public static Card ThreeOfClubs { get => new Card(Suite.Clubs, Value.Three); }
            public static Card TwoOfClubs   { get => new Card(Suite.Clubs, Value.Two); }

            public static Card AceOfDiamonds    { get => new Card(Suite.Diamonds, Value.Ace); }
            public static Card KingOfDiamonds   { get => new Card(Suite.Diamonds, Value.King); }
            public static Card QueenOfDiamonds  { get => new Card(Suite.Diamonds, Value.Queen); }
            public static Card JackOfDiamonds   { get => new Card(Suite.Diamonds, Value.Jack); }
            public static Card TenOfDiamonds    { get => new Card(Suite.Diamonds, Value.Ten); }
            public static Card NineOfDiamonds   { get => new Card(Suite.Diamonds, Value.Nine); }
            public static Card EightOfDiamonds  { get => new Card(Suite.Diamonds, Value.Eight); }
            public static Card SevenOfDiamonds  { get => new Card(Suite.Diamonds, Value.Seven); }
            public static Card SixOfDiamonds    { get => new Card(Suite.Diamonds, Value.Six); }
            public static Card FiveOfDiamonds   { get => new Card(Suite.Diamonds, Value.Five); }
            public static Card FourOfDiamonds   { get => new Card(Suite.Diamonds, Value.Four); }
            public static Card ThreeOfDiamonds  { get => new Card(Suite.Diamonds, Value.Three); }
            public static Card TwoOfDiamonds    { get => new Card(Suite.Diamonds, Value.Two); }
        }

        class Deck
        {
            public static List<Card> SupportedCards { get; } = new List<Card> {
                Card.AceOfSpades,   Card.AceOfHearts,   Card.AceOfClubs,   Card.AceOfDiamonds,
                Card.KingOfSpades,  Card.KingOfHearts,  Card.KingOfClubs,  Card.KingOfDiamonds,
                Card.QueenOfSpades, Card.QueenOfHearts, Card.QueenOfClubs, Card.QueenOfDiamonds,
                Card.JackOfSpades,  Card.JackOfHearts,  Card.JackOfClubs,  Card.JackOfDiamonds,
                Card.TenOfSpades,   Card.TenOfHearts,   Card.TenOfClubs,   Card.TenOfDiamonds,
                Card.NineOfSpades,  Card.NineOfHearts,  Card.NineOfClubs,  Card.NineOfDiamonds,
                Card.EightOfSpades, Card.EightOfHearts, Card.EightOfClubs, Card.EightOfDiamonds,
                Card.SevenOfSpades, Card.SevenOfHearts, Card.SevenOfClubs, Card.SevenOfDiamonds,
                Card.SixOfSpades,   Card.SixOfHearts,   Card.SixOfClubs,   Card.SixOfDiamonds,
                Card.FiveOfSpades,  Card.FiveOfHearts,  Card.FiveOfClubs,  Card.FiveOfDiamonds,
                Card.FourOfSpades,  Card.FourOfHearts,  Card.FourOfClubs,  Card.FourOfDiamonds,
                Card.ThreeOfSpades, Card.ThreeOfHearts, Card.ThreeOfClubs, Card.ThreeOfDiamonds,
                Card.TwoOfSpades,   Card.TwoOfHearts,   Card.TwoOfClubs,   Card.TwoOfDiamonds
            };

            private List<Card> Cards { get; set; } = new List<Card>(SupportedCards);

            public Deck() { }

            public static Deck Shuffled { get => new Deck().Shuffle(); } 

            private static Deck InitializeFromExisting(Deck deck)
            {
                if (deck == null) {
                    throw new ArgumentNullException("deck");
                }

                return new Deck(deck.Cards);
            }

            private Deck(List<Card> cards)
            {
                Cards = cards;
            }

            public Card PopCard() 
            {
                if (Cards.Count == 0) {
                    throw new InvalidOperationException("Cannot pop off an empty deck.");
                }

                var topIndex = Cards.Count - 1;
                var topCard  = Cards[topIndex];

                Cards.RemoveAt(topIndex);

                return topCard;
            }

            public Deck Shuffle() 
            {
                var cards = new List<Card>(Cards.Select((x) => x));
                var rand  = new Random();

                for (Int32 index = 0; index < cards.Count; ++index) {
                    var randIndex    = rand.Next(1 + index);
                    var temp         = cards[index];
                    cards[index]     = cards[randIndex];
                    cards[randIndex] = temp;
                }

                return new Deck(cards);
            }

            public Int32 Count { get => Cards.Count; }

            public override String ToString() =>
                String.Join("\n", Cards.AsEnumerable().Reverse());
        }

        class Player
        {
            private const Int32 InitialDrawnCardCount = 5;

            private List<Card> Hand { get; set; } = new List<Card>();

            private readonly Dictionary<Card, Int32> _scoreTable;

            private Dictionary<Card, Int32> ScoreTable { get => _scoreTable; }

            public String Name { get; private set; }

            public Player(String name, Deck deck, Dictionary<Card, Int32> scoreTable)
            {
                if (name == null) {
                    throw new ArgumentNullException("name");
                }

                if (deck == null) {
                    throw new ArgumentNullException("deck");
                }

                if (scoreTable == null) {
                    throw new ArgumentNullException("scoreTable");
                }

                _scoreTable = scoreTable;
                Name = name;

                DrawCards(deck, InitialDrawnCardCount);
            }

            public void ShowHand()
            {
                Console.WriteLine("Player {0} initially has the following cards:", Name);

                var hand = String.Join("\n", Hand);

                Console.WriteLine(hand);
                Console.WriteLine();
            }

            public void DrawCards(Deck deck, Int32 times)
            {
                if (deck == null) {
                    throw new ArgumentNullException("deck");
                }

                for (Int32 count = 0; count < times; ++count) {
                    DrawCard(deck);
                }
            }

            public void DrawCard(Deck deck)
            {
                if (deck == null) {
                    throw new ArgumentNullException("deck");
                }

                var card = deck.PopCard();
                
                Hand.Add(card);
            }

            public override String ToString() => String.Join("\n", Hand);

            public Int32 Score { get => ComputeScore(ScoreTable); }

            private Int32 ComputeScore(Dictionary<Card, Int32> scoreTable)
            {
                if (scoreTable == null) {
                    throw new ArgumentNullException("scoreTable");
                }

                var score = Hand.Select((card) => scoreTable[card]).Sum();

                return score;
            }
        }

        private static Dictionary<Card, Int32> GenerateScoreTable()
        {
            var table = new Dictionary<Card, Int32>();
            
            foreach (var card in Deck.SupportedCards) {
                table[card] = (Int32)card.CurrentValue;
            }

            return table;
        }

        //private static Player GetWinner(params Player[] players)
        //{
        //    if (players.Length == 0) {
        //        throw new InvalidOperationException("No players given.");
        //    }

        //    var winner = players.First();

        //    foreach (var player in players) {
        //        winner = winner.Score < player.Score ? winner : player;
        //    }

        //    return winner;
        //}

        private static Player GetWinner(params Player[] players)
        {
            if (players.Length == 0) {
                throw new InvalidOperationException("No players given.");
            }

            var winner = players.First();

            foreach (var player in players) {
                winner = winner.Score < player.Score ? winner : player;
            }

            if (players.Count((player) => player.Score == winner.Score) > 1) {
                return null;
            }

            return winner;
        }

        static void Main(String[] args)
        {
            Int32 count = 255;

            for (var times = 0; times < count; ++times) 
            {
                var scoreTable = GenerateScoreTable();
                var deck       = Deck.Shuffled;
                var players    = new Player[] {
                    new Player("william",  deck, scoreTable),
                    new Player("Gerard", deck, scoreTable)
                };
            
                Console.WriteLine("Game #{0}\n", times);

                foreach (var player in players) {
                    player.ShowHand();
                }

                while (deck.Count > 0) 
                {
                    foreach (var player in players) {
                        player.DrawCard(deck);
                    }
                }

                foreach (var player in players) {
                    player.ShowHand();
                }

                var winner = GetWinner(players);

                if (winner == null) {
                    Console.WriteLine("The game was a draw!");
                } else {
                    Console.WriteLine("The winner is {0}!",
                        winner.Name, winner.Score);
                }

                var stats = players.Select((player) =>
                    String.Format("{0} has a score of {1}.", player.Name, player.Score));

                Console.WriteLine(String.Join("\n", stats));
                Console.WriteLine();

                Console.WriteLine("Please press any key to continue...");
                Console.ReadKey();
                Console.WriteLine();
            }
        }
    }
}

