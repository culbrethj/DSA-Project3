#pragma once
#include <string>
using namespace std;

struct Packet{
	string buyer_county;
	string buyer_name;
	string buyer_state;
	string seller_county;
	string seller_name;
	string seller_state;
	int slave_age;
	string slave_gender;
	string slave_name;
	string slave_skin;
	string transaction_date;
	int transaction_num_adults;
	int transaction_num_children;
	int transaction_num_total;
	double transaction_discount;
	string transaction_payment;
	double transaction_interest_rate;
	double transaction_price;

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
};