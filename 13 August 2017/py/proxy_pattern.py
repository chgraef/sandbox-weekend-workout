class Subject:
    def request(self):
        print('making request...')

class Proxy:
    def __init__(self):
        self._subject = Subject()

    @property
    def subject(self):
        return self._subject

    def request(self):
        print('proxy checking your credentials...')
        self.subject.request()

conn = Proxy()
conn.request()
