 #include <iostream>
constexpr float gravity {9.8};

int inHeight ()
{
   int h{0};
   std::cout << "Enter height: " << std::endl;
   std::cin >> h;
   return h;
};
float calcDistance ( float t )
{
  //distance fallen = gravity_constant * x_seconds^2 / 2
  float l{0.0};
  l = (gravity * (t*t)) / 2.0;
  return l;
};
void outHeight( float seq )
{
	if (seq > 0) std::cout << seq   << std::endl;
	else         std::cout << "..." << std::endl;
}
int main () 
{
   float height = inHeight();
   
   std::cout << "0: " << height << "\n";
   std::cout << "1: "; outHeight(height - calcDistance(1));
   std::cout << "2: "; outHeight(height - calcDistance(2));
   std::cout << "3: "; outHeight(height - calcDistance(3));
   std::cout << "4: "; outHeight(height - calcDistance(4));
   std::cout << "5: "; outHeight(height - calcDistance(5));
   
   return 0;
};
