build_dir ?=build
bin_dir   ?=$(build_dir)/bin

clean:
	rm -rf $(build_dir)

all : clean compile link run

compile:
	mkdir -p $(bin_dir);
	$(call comp,Admin)
	$(call comp,Customer)
	$(call comp,main)
	$(call comp,Menu)
	$(call comp,New_Inventory)
	$(call comp,Password)
	$(call comp,Purchased_Data)
	$(call comp,Supplier)
	$(call comp,Validate_input)

link:
	g++ -o $(bin_dir)/medical.exe $(build_dir)/*.o

run:
	$(bin_dir)/medical.exe

build_with_cmake :
	rm -rf build/*
	cmake -S . -B build -G "MinGW Makefiles"
	cmake --build build -j 10 --target install

define comp
	g++ -c -I include src/$(1).cpp -o $(build_dir)/$(1).o
endef