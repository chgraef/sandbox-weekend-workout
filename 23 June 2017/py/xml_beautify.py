def xml_beautify(xml_data):
    def tag_is_opening(tag):
        return not tag_is_closing(tag)

    def tag_is_closing(tag):
        return tag.startswith('</')

    def tag_get_name(tag):
        tag_end = tag.find('>')

        if tag_end >= 0:
            if tag_is_opening(tag):
                return tag[1:tag_end].strip()
            else:
                return tag[2:tag_end].strip()
        
    def tag_find(s, start=0):
        tag_begin = s.find('<', start)
        tag_end   = s.find('>', 1 + tag_begin)

        if any(value < 0 for value in [tag_begin, tag_end]):
            return None
        
        return tag_begin, 1 + tag_end

    def tag_open_find(s, start=0):
        index = start - 1

        while True:
            tag_data = tag_find(s, 1 + index)

            if tag_data:
                tag_beg, tag_end = tag_data[0], tag_data[1]
                tag = s[tag_beg:tag_end]

                if tag_is_opening(tag):
                    return tag_beg, tag_end
                else:
                    index = tag_end
            else:
                break

    def tag_closing_find(s, start=0):
        index = start - 1

        while True:
            tag_data = tag_find(s, 1 + index)

            if tag_data:
                tag_beg, tag_end = tag_data[0], tag_data[1]
                tag = s[tag_beg:tag_end]

                if tag_is_closing(tag):
                    return tag_beg, tag_end
                else:
                    index = tag_end
            else:
                break

    INDENT    = '    '

    tag_index = 0
    lines     = []
    depth     = 0

    while True:
        tag_data = tag_find(xml_data, tag_index)

        if tag_data:
            tag_beg, tag_end = tag_data[0], tag_data[1]
            tag         = xml_data[tag_beg:tag_end].strip()
            tag_content = xml_data[tag_index:tag_beg].strip()
            tag_index   = tag_end

            if tag_is_closing(tag):
                if len(tag_content) > 0: 
                    lines.append(INDENT * depth + tag_content)
                
                depth -= 1
                lines.append(INDENT * depth + tag)
            elif tag_is_opening(tag):
                lines.append(INDENT * depth + tag)
                depth += 1
        else:
            break

    return '\n'.join(lines)

xml_data = '''
	<emperors>
	  <emperor>
	    <name>Claudius</name>
	    <hometown>Lugdunum, Gaul</hometown>
	    <reign>41 A.D. - 54 A.D.</reign>
	    <wasGood>Who knows?</wasGood>
	  </emperor>
	  <emperor>
	    <name>Diocletian</name>
	    <hometown>Salona, Dalmatia</hometown>
	    <reign>284 A.D. - 305 A.D.</reign>
	    <wasGood>Yes</wasGood>
	  </emperor>
	</emperors>
	'''

xml_data_bad = '\n'.join(map(lambda s: s.strip(), xml_data.split('\n')))

xml_beautiful = xml_beautify(xml_data_bad)

print(xml_beautiful)

#print('\n'.join(xml_beautiful))
