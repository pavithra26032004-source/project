books=[]
def add_book():
    book_id=int(input("Enter bookID:"))
    title=input("Enter book title:")
    author=input("Enter Author name:")
    book={
        "id":book_id,
        "title":title,
        "author":author,
        "status":"Available"
    }
    books.append(book)
    print("Book added successfully:\n")

def view_book():
    if len(books)==0:
        print("No books available.\n")
    else:
        print("\n Library books")
        print("_"*50)
        for book in books:
            print("Book ID:",book["id"])
            print("Title:",book["title"])
            print("Author:",book["author"])
            print("Status:",book["status"])
            print("_"*50)

def search_book():
    book_id=int(input("Enter book ID to search:"))
    for book in books:
        if book in books:
            if book["id"]==book_id:
                print("book found")
                print(book)
                return
    print("book not found.\n")

def issue_book():
    book_id=int(input("Enter book ID to issue:"))
    for book in books:
        if book["id"]==book_id:
            if book["status"]=="Available":
                book["status"] = "Issued"
                print(book)
                print("book issued successfully.\n")
            else:
                print("book is already issued.\n")
                return
        else:
            print("book not found.\n")

def return_book():
    book_id=int(input("Enter book ID to return:"))
    for book in books:
        if book["id"] == book_id:
            if book["status"] == "Issued":
                book["status"] = "Available"
                print("book returned successfully.\n")
            else:
                print("book is already Available.\n")
                return
        else:
            print("book not found.\n")

def delete_book():
    book_id = int(input("Enter book ID to delete:"))
    for book in books:
        if book["id"] == book_id:
             books.remove(book)
             print("book deleted successfully.\n")
             return
    print("book not found.\n")

def main():
    while True:
        print("\n=====Library Management system=====")
        print("1.Add book")
        print("2.view book")
        print("3.search book")
        print("4.Issue book")
        print("5.Return book")
        print("6.delete book")
        print("7.Exit")
        choice=int(input("Enter your choice:"))
        if choice==1:
            add_book()
        elif choice==2:
            view_book()
        elif choice == 3:
            search_book()
        elif choice == 4:
            issue_book()
        elif choice == 5:
            return_book()
        elif choice == 6:
            delete_book()
        elif choice == 7:
            print("thank you! Visit Again.")
            break
        else:
            print("Invalid choice.please try again.")

main()


