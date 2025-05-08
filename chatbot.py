def welcome():
    print("****** Welcome to Food Shop ******")
    print("I am Teja, created by Tejas.")
    print()

def get_customer_info():
    name = input("Can I know your good name? ")
    print(f"Hey {name}! Good to see you here!")
    print("You're in the right place. I'll help you book your food and drinks.\n")
    return name

def show_menu():
    print("Here is your menu with prices:")
    print("1. Pizza        - Rs.200")
    print("2. Mango Juice  - Rs.70")
    print("3. Apple Juice  - Rs.80\n")

def get_order_choice():
    choice = input("Please select the product you wish (Pizza/Mango Juice/Apple Juice): ").strip().lower()
    menu_items = {
        "pizza": 200,
        "mango juice": 70,
        "apple juice": 80
    }
    if choice in menu_items:
        return choice.title(), menu_items[choice]
    else:
        print("Invalid selection. Thank you for visiting. Have a nice day!")
        return None, None

def take_order(name, product, price):
    print(f"\nThank you for choosing {product}!\n")
    mobile = input("Enter your mobile number: ")
    address = input("Enter your delivery address: ")

    print("\nChoose mode of payment:")
    print("1. Online")
    print("2. Cash on Delivery")
    payment_choice = input("Enter your choice (1 or 2): ")
    payment_mode = "Cash on Delivery" if payment_choice == "2" else "Online"
    print("\n******* Order Summary *******")
    print(f"Customer Name   : {name}")
    print(f"Product Name    : {product}")
    print(f"Price           : Rs.{price}")
    print(f"Payment Mode    : {payment_mode}")
    print(f"Delivery Address: {address}\n")
    confirm = input("Please confirm your order by pressing 1, or press 0 to cancel: ")
    if confirm == "1":
        print("\nYour order is booked successfully!")
        print("Thank you for your interest. Have a nice day!")
    else:
        print("Order cancelled. Thank you for visiting!")

welcome()
customer_name = get_customer_info()
show_menu()
product, price = get_order_choice()

if product and price:
    take_order(customer_name, product, price)
