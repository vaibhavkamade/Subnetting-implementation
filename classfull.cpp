#include<bits/stdc++.h>
using namespace std;

int checker(string &str){
    
    string temp = "";
    
    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == '.') break;
        temp += str[i];
    }
    
    int temp1 = stoi(temp);
    
    return temp1;
}

int binary(int decimal){
    int remainder = 0;
    int product = 1;
    int binaryForm = 0;
    while (decimal != 0) {
    remainder = decimal % 2;
    binaryForm = binaryForm + (remainder * product);
    decimal = decimal / 2;
    product *= 10;
  }

  return binaryForm;
}

//function to create newsubnet

string subnetGen1(int n){
    
    string newSubnet = "11111111.11111111.11111111.11111111";
    int i = newSubnet.size()-1;
    while(n){
        if(newSubnet[i] == '.'){
            i--;
            continue;
        }
        newSubnet[i--] = '0';
        n--;
    }

    return newSubnet;
}

pair<int,int> subnetGen2(string newSubnet){
    int count = 0;
    int i = newSubnet.size()-1;
    int octet = 4;
    while(newSubnet[i] != '1'){
        if(newSubnet[i] == '.'){
            octet -= 1;
            count = 0;
        }else{
            count++;
        }
        i--;
        
    }

    pair<int,int> p = make_pair(pow(2,count),octet);
    return p;
}


string network1(string &IP , char c){
    string network =  "";
    int count=0;
    if(c == 'A'){
        for(int i = 0 ; count <= 0 ; i++ ){
            if(IP[i] == '.'){
             count++;
            }    
            network += IP[i];
        }
        string temp = "0.0.0";
        network = network + temp;
    }else if(c == 'B'){
         for(int i = 0 ; count <= 1 ; i++ ){
            network += IP[i];
            if(IP[i] == '.') count++;
        }
        string temp = "0.0";
        network = network + temp;
    }else if(c == 'C'){
        for(int i = 0 ; count <= 2 ; i++ ){
            network += IP[i];
            if(IP[i] == '.') count++;
        }
        string temp = "0";
        network = network + temp;
    }
    
    return network;
}


string subDeci(int octet , int subGen ){
    string ans = "";
    int diff = 255 - subGen;
    if(octet == 4){
        
        ans = "255.255.255." + to_string(subGen);
    }else if(octet == 3){
        ans = "255.255." + to_string(diff) + "0";
    }

    return ans;
}


void addressRange(vector<string> &ans , int octet , int subGen , string network){

    int tempOctet = 4;
    int temp = 0;
    string o1,o2,o3,o4;
    int count = 0;
    for(int i = 0 ; i < network.size() ; i++ ){
        if(network[i] == '.') {
            count++;
            continue;
        }
        if(count == 0) o1 += network[i];
        if(count == 1) o2 += network[i];
        if(count == 2) o3 += network[i];
        if(count == 3) o4 += network[i];
    }


    // while(tempOctet <= octet){

    //     int temp = 0;
        
    //     // if(tempOctet== 1){

    //     //    while (temp <= 256)
    //     //     {
    //     //     string str =  o1+ "." + o2 + "." + to_string(temp-1)  +"."+ to_string(temp-1);
    //     //     ans.push_back(str);
    //     //     temp += temp;
    //     //     if(temp >= 256) tempOctet++;
    //     //     }
    //     // }
    // }


    if(octet == 4){

        while (temp <= 256)
        {
        string str =  o1+ "." + o2 + "." + o3 +"."+ to_string(temp);
        ans.push_back(str);
        temp  += subGen;
        }
    }else if(octet == 3){
        while (temp <= 256)
        {
        string str =  o1+ "." + o2 + "." + to_string(temp) +"."+ o4;
        ans.push_back(str);
        temp  += subGen;
        }
    }

       
      
       

        



}

int main(){
    
    string str;
    
    int host;
    cout << "Please Enter the IP Address " << endl;
    cin >> str;
    
    int class1 = checker(str);
    // cout<<class1<<endl;
    char c;
    if(class1 >= 0 && class1 <= 127){
        cout <<"IP address belong to class A " << endl;
        c = 'A';
    }else if(class1 >= 128 && class1 <= 192){
        cout <<"IP address belong to class B " << endl;
        c = 'B';
    }else if(class1 >= 193 && class1 <= 224){
        cout <<"IP address belong to class C " << endl;
        c = 'C';
    }else{
        cout << "Network can't be used for Subnetting " << endl;
    }

    cout << "Enter the number of host " << endl;
    cin >> host;

    int binaryHost = binary(host);
    //counting number of bits in the host
    int count = log2(host) + 1;
    cout << binaryHost<<endl;

    // while(binaryHost){
    //     count += 1;
    //     binaryHost = binaryHost >> 1;
    // }
    
    cout << count << " No of bits are reserved from right position " << endl;

    string newSubnet1 = subnetGen1(count);
    cout << "New subnet generated is " << newSubnet1 << endl;
    pair<int,int> p1 = subnetGen2(newSubnet1);
    int octet = p1.second;
    int newSubnet2 = p1.first;

    cout << "New subnet generator is " << newSubnet2 << endl;
    cout << "Octet is " << octet << endl;
    string netId = network1(str,c);
    cout<<"Network adress id "<< network1(str,c) << endl;
    cout << "Subnet in decimal "<< subDeci(octet,newSubnet2)<<endl;

    vector<string> ans;
    addressRange(ans,octet,newSubnet2,netId);
    for(auto it:ans){
        cout<<it<<" "<<endl;
    }
    return 0;
    
    //Made with ❤️ ;
}




