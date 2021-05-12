from Crypto.Hash import SHA256
text = 'The big brown fox jumped over the lazy dog'

hash = SHA256.new(text)
print(hash.digest())





