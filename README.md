#Contacts

An App for Contacts

File Type:
- .pcc : A single individual's contacts. Used to send/receive. Stored as binary
- .fcc : For file storage, batch contacts. Not for sending
- .idx : Index for quickly finding which fcc file contains your contact. easier to search. maybe binary

class Address? (Maybe just a string)
    -Number and Street
    -City
    -State/Country
    -ZIP

Class Phone:
    4 ints:
    a-bbb-ccc-dddd
Class Person:
    -FName, MName LName
    -Company //not yet
    -Contact (vector of contacts?) will need multiple
    -Address (vector of addresses)

Read and write functions: 
- read in from either file type to create C



GUI: 



Questions: 
- does ~Person need to delete a datetime, addr?
    
