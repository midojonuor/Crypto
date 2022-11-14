# import blake3
from hashlib import blake2s
import hmac, hashlib
from hmac import compare_digest



if __name__ == "__main__":


    print ("\n== We can also use Blake2 for HMAC ==")
    
    # Example of converting the key to stream of bytes
    # secret_key = bytes([32] * 32)
    # secret_key = b"\x20" * 32
    
    # example of converting the message to stream of bytes
    # msg = bytes([186] * 128)
    # msg = b"\xba" * 128

    secret_key = b"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x10\x11\x12\x13\x14\x15\x16"

    msg = b"\xaa\xbb\xcc\xdd\xee\xff"


    hm = hmac.HMAC(secret_key, digestmod=blake2s)
    hm.update(msg)

    print ("\nHMAC: ", hm.hexdigest())
