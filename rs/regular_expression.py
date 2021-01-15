import re

def matcher(regex, string):
    match = re.search(regex, string)
    if match is None: return False
    return True

def detect_spanish_laughter(string):
    return matcher('[jaJA]{3,}', string)

def valid_phone(string):
        return matcher('^(0|\+359|359)?[0-9]\d{8,8}$', string)

def get_links(text):
    return matcher('', text)