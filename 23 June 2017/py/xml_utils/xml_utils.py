def tag_get_name(tag):
    import re

    pattern   = r'</?([A-Za-z0-9]+)'
    occurence = re.search(pattern, tag)

    if occurence:
        return occurence.group(1)

def tag_find(s, start=0):
    tag_begin = s.find('<', start)
    tag_end   = s.find('>', 1 + tag_begin)

    if any(value < 0 for value in [tag_begin, tag_end]):
        return None

    return tag_begin, 1 + tag_end

def tag_closing_find_by_name(s, name, start=0):
    import re

    pattern   = r'</\s*' + name
    occurence = re.search(pattern, s[start:])

    if occurence:
        tag_begin = occurence.start()
        tag_end   = s.find('>', 1 + tag_begin)

        if tag_end:
            return tag_begin, 1 + tag_end
            
