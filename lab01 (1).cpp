#include <iostream>
using namespace std;

struct product
{
  string name;
  float price;
  int amount;
  int quantity;
  double weight;
  product* next;
};

void add(product*& head, string name, float price, int amount, int quantity, double weight)
{
  product* new_product = new product;
  new_product->name = name;
  new_product->price = price;
  new_product->amount = amount;
  new_product->quantity = quantity;
  new_product->weight = weight;
  new_product->next = head;
  head = new_product;
}

void remove(product*& head, string name)
{
  if (head == NULL)
  {
    cout << "List is empty\n";
    return;
  }

  if (head->name == name)
  {
    product* tmp = head;
    head = head->next;
    delete tmp;
    return;
  }

  product* prev = NULL;
  product* current = head;

  while (current != NULL && current->name != name)
  {
    prev = current;
    current = current->next;
  }

  if (current == NULL)
  {
    cout << "Element not found\n";
    return;
  }

  prev->next = current->next;
  delete current;
}

void print(product* head)
{
  if (head == NULL)
  {
    cout << "List is empty\n";
    return;
  }

  product* current = head;

  while (current != NULL)
  {
    cout << "Product: " << current->name << "\nPrice: " << current->price << "\nAmount: " << current->amount << "\nQuantity: " << current->quantity << "\nWeight: " << current->weight << endl;
    current = current->next;
  }
}

int main()
{
  product* head = NULL;

  while (true)
  {
    cout << "1. Add product\n";
    cout << "2. Remove product\n";
    cout << "3. Print list\n";
    cout << "4. Exit\n";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
      string name;
      float price;
      int amount;
      int quantity;
      double weight;

      cout << "Enter product name: ";
      cin >> name;
      cout << "Enter product price: ";
      cin >> price;
      cout << "Enter product amount: ";
      cin >> amount;
      cout << "Enter product quantity: ";
      cin >> quantity;
      cout << "Enter product weight: ";
      cin >> weight;

      add(head, name, price, amount, quantity, weight);
      break;
    }
    case 2:
    {
      string name;

      cout << "Enter product name to remove: ";
      cin >> name;

      remove(head, name);
      break;
    }
    case 3:
      print(head);
      break;
    case 4:
      return 0;
    default:
      cout << "Invalid choice\n";
    }
  }

  return 0;
}