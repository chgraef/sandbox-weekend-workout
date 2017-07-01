import unittest
from xml_utils import tag_get_name

class TestTagGetName(unittest.TestCase):
    MESSAGE = 'Expected: {}\nActual: {}'

    def test_OpeningTagNoSpace(self):
        tag = '<hello>'
		
        expected = 'hello'
        actual   = tag_get_name(tag)

        self.assertEqual(expected, actual, TestTagGetName.MESSAGE.format(expected, actual))

    def test_ClosingTagNoSpace(self):
        tag = '</world>'

        expected = 'world'
        actual   = tag_get_name(tag)

        self.assertEqual(expected, actual, TestTagGetName.MESSAGE.format(expected, actual))

    def test_OpeningTagLeadingWhitespace(self):
        tag = '    <fields>'

        expected = 'fields'
        actual   = tag_get_name(tag)

        self.assertEqual(expected, actual, TestTagGetName.MESSAGE.format(expected, actual))

    def test_ClosingTagLeadingWhitespace(self):
        tag = '     </tears>'

        expected = 'tears'
        actual   = tag_get_name(tag)

        self.assertEqual(expected, actual, TestTagGetName.MESSAGE.format(expected, actual))

    def test_OpeningTagTrailingWhitespace(self):
        tag = '<laughter>    '

        expected = 'laughter'
        actual   = tag_get_name(tag)

        self.assertEqual(expected, actual, TestTagGetName.MESSAGE.format(expected, actual))

    def test_ClosingTagTrailingWhitespace(self):
        tag = '</laughter>       '

        expected = 'laughter'
        actual   = tag_get_name(tag)

        self.assertEqual(expected, actual, TestTagGetName.MESSAGE.format(expected, actual))

    def test_NoTag(self):
        tag = 'laughter'

        expected = None
        actual   = tag_get_name(tag)

        self.assertEqual(expected, actual, TestTagGetName.MESSAGE.format(expected, actual))

if __name__ == '__main__':
    unittest.main()
