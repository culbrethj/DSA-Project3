#pragma once
#include <string>
using namespace std;

struct Packet{
	string buyer_county; //2
	string buyer_name; //3
	string buyer_state; //5
	string seller_county; //6
	string seller_name; //7
	string seller_state; //9
	int slave_age; //10
	string slave_gender; //11
	string slave_name; //12
	string slave_skin; //13
	string transaction_date; //14
	int transaction_num_adults; //15
	int transaction_num_children; //16
	int transaction_num_total; //17
	double transaction_discount; //18
	string transaction_payment; //19
	double transaction_interest_rate; //20
	double transaction_price; //21

    Packet(string buyer_county, 
    string buyer_name, 
    string buyer_state, 
    string seller_county, 
    string seller_name, 
    string seller_state, 
    int slave_age, 
    string slave_gender, 
    string slave_name, 
    string slave_skin, 
    string transaction_date, 
    int transaction_num_adults, 
    int transaction_num_children, 
    int transaction_num_total, 
    double transaction_discount, 
    string transaction_payment, 
    double transaction_interest_rate, 
    double transaction_price)
    :
    buyer_county(buyer_county),
    buyer_name(buyer_name),
    buyer_state(buyer_state),
    seller_county(seller_county),
    seller_name(seller_name),
    seller_state(seller_state),
    slave_age(slave_age),
    slave_gender(slave_gender),
    slave_name(slave_name),
    slave_skin(slave_skin),
    transaction_date(transaction_date),
    transaction_num_adults(transaction_num_adults),
    transaction_num_children(transaction_num_children),
    transaction_num_total(transaction_num_total),
    transaction_discount(transaction_discount),
    transaction_payment(transaction_payment),
    transaction_interest_rate(transaction_interest_rate),
    transaction_price(transaction_price) {}
    Packet() {}
};