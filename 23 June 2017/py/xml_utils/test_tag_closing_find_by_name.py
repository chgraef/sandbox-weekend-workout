import unittest
from xml_utils import tag_closing_find_by_name

class TestTagClosingFindByName(unittest.TestCase):
    MESSAGE = 'Expected: {}\nActual: {}'

    def test_TargetIsFirstTag(self):
        tag  = '</legion>'
        name = 'legion'

        expected = (0, len(tag))
        actual   = tag_closing_find_by_name(tag, name)

        self.assertEqual(expected, actual, TestTagClosingFindByName.MESSAGE.format(expected, actual))

    def test_TargetIsSecondUnnestedTag(self):
        tags = '<legion></legion><city></city>'
        name = 'city'

        expected = (tags.find('</city>'), len(tags))
        actual   = tag_closing_find_by_name(tags, name)

        self.assertEqual(expected, actual, TestTagClosingFindByName.MESSAGE.format(expected, actual))

    def test_TargetIsNestedTag(self):
        tags = '<legion><commander></commander></legion>'
        name = 'commander'

        exp_tag_beg = tags.find('</commander>')
        exp_tag_end = tags.find('>', exp_tag_beg) + 1

        expected = (exp_tag_beg, exp_tag_end)
        actual   = tag_closing_find_by_name(tags, name)

        self.assertEqual(expected, actual, TestTagClosingFindByName.MESSAGE.format(expected, actual))

if __name__ == '__main__':
	  unittest.main()
