//#include <iostream>
//#include <bitset>
//
//
//using namespace std;
//
//
//short max_all_input_val = ~(1 << (sizeof(short) * 8 - 1));
//short min_all_input_val = (1 << (sizeof(short) * 8-1 ));
//short max_input = sizeof(short) * 8;
//
//
//short checkbit(short s)
//{
//    short pos = sizeof(short) * 8;
//    if ((s & (1 << (pos - 1))) == 0)
//    {
//
//        return 0;
//    }
//    else
//    {
//        cout << "The bit is set" << endl;
//        return 1;
//    }
//}
//
//short preserved_sig_right(short s)
//{
//    short pre_value = checkbit(s);
//    short prs_val = (s >> 1) | (s & (pre_value << (sizeof(s) * 8 - 1)));
//    return prs_val;
//}
//
//short setbit(short s, bool val)
//{
//    short leftmostBit = 1 << (sizeof(s) * 8 - 1);
//    short clearedNum = s & (~leftmostBit); // Clear the leftmost bit
//    short newNum = clearedNum | (val << (sizeof(s) * 8 - 1)); // Set the leftmost bit to the desired value
//    return newNum;
//}
//
//
//short booth_alg(short M,short Q_multi) 
//{
//    short n = sizeof(M) * 8;
//    short ac = 0;
//    bool q_zero = 0;
//    bool q_one = Q_multi & 1;
//    cout << "This is M value " << bitset<16>(M) << endl;
//
//    while (n > 0)
//    {
//        cout << "N = " << n << endl;
//        cout << q_one << endl;
//        cout << q_zero << endl << endl;
//        cout << "Current value of Q " << bitset<16>(Q_multi) << endl;
//        if (q_one == q_zero)
//        {
//            cout << "Both qone and qzero is equal " << endl;
//            cout << "This is Ac " << bitset<16>(ac) << endl;
//            q_zero = Q_multi & 1;
//            cout << "This is updated Qzero :" << q_zero << endl;
//            Q_multi = (setbit(Q_multi >> 1, ac & 1));
//
//            cout << "This is Q_multi after shift " << bitset<16>(Q_multi) << endl;
//            ac = preserved_sig_right(ac);
//            cout << "This is Ac after shift " << bitset<16>(ac) << endl;
//
//            q_one = Q_multi & 1;
//            cout << "This is updated Qone :" << q_one << endl;
//            n = n - 1;
//
//        }
//        else if (q_one == 1 && q_zero == 0)
//        {
//            ac = ac + (-M);
//            cout << "This is Ac A=A-M " << bitset<16>(ac) << endl;
//            q_zero = Q_multi & 1;
//            cout << "This is updated Qzero :" << q_zero << endl;
//            Q_multi = (setbit(Q_multi >> 1, ac & 1));
//            cout << "This is Q_multi after shift " << bitset<16>(Q_multi) << endl;
//            q_one = Q_multi & 1;
//            cout << "This is updated Qone :" << q_one << endl;
//            ac = preserved_sig_right(ac);
//            cout << "This is Ac after shift " << bitset<16>(ac) << endl;
//            n = n - 1;
//        }
//        else if (q_one == 0 && q_zero == 1)
//        {
//            ac = ac + M;
//            cout << "This is Ac A=A+M " << bitset<16>(ac) << endl;
//            q_zero = Q_multi & 1;
//            cout << "This is updated Qzero :" << q_zero << endl;
//            Q_multi = (setbit(Q_multi >> 1, ac & 1));
//            cout << "This is Q_multi after shift " << bitset<16>(Q_multi) << endl;
//            q_one = Q_multi & 1;
//            cout << "This is updated Qone :" << q_one << endl;
//            ac = preserved_sig_right(ac);
//            cout << "This is Ac after shift " << bitset<16>(ac) << endl;
//            n = n - 1;
//
//        }
//
//    }   
//
//    return Q_multi;
//}
//
//bool veri_s(short s)
//{
//    if (s < max_all_input_val && s>min_all_input_val)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//
//}
//
//int main() {
//    short M ;    
//    short Q_multi ;
//    bool flagged = true;
//    
//    do 
//    {
//        cout << "Insert the first number : ";
//        cin >> M;
//        if (cin.fail()) {
//            cin.clear();
//            cout << "Inserted number out of range" << endl;           
//            
//        }
//        else {
//            try
//            {
//                if (veri_s(M) == true)
//                {
//                    cout << "Insert the number for n: ";
//                    cin >> Q_multi;
//                    if (cin.fail()) {
//                        cin.clear();
//                        cout << "Inserted number out of range cin failed" << endl;
//                        continue;
//                    }
//                    else
//                    {
//                        if (veri_s(Q_multi) == true)
//                        {
//                            short result = booth_alg(M, Q_multi);
//                            cout << M << "x" << Q_multi << "= " << result;
//                            flagged = false;
//                        }
//                        else
//                        {
//                            cout << "Inserted number out of range" << endl;                            
//                        }
//                    }                    
//                   
//                }
//                else
//                {
//
//                    cout << "Inserted number out of range" << endl;
//                    
//                }
//            }
//            catch (...)
//            {
//                cout << "Inserted number out of range" << endl;
//                break;
//            }
//         
//            
//        }      
//        
//        
//    } while (flagged);
//   
//
//
//    return 0;
//}