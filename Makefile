build_dir ?=build
bin_dir   ?=$(build_dir)/bin


clean:
	rm -rf $(build_dir)

all : clean compile link run

compile:
	mkdir $(build_dir) && mkdir $(bin_dir);\
	g++ -c Admin.cpp -o $(build_dir)/Admin.o ;\
	g++ -c Customer.cpp -o $(build_dir)/Customer.o ;\
	g++ -c main.cpp -o $(build_dir)/main.o ;\
	g++ -c Menu.cpp -o $(build_dir)/Menu.o ;\
	g++ -c New_Inventory.cpp -o $(build_dir)/New_Inventory.o ;\
	g++ -c Password.cpp -o $(build_dir)/Password.o ;\
	g++ -c Purchased_Data.cpp -o $(build_dir)/Purchased_Data.o ;\
	g++ -c Supplier.cpp -o $(build_dir)/Supplier.o ;\
	g++ -c Validate_input.cpp -o $(build_dir)/Validate_input.o

link:
	g++ -o $(bin_dir)/medical.exe $(build_dir)/*.o

run:
	$(bin_dir)/medical.exe