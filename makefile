all:
	gcc src/*.c lib/libdap_shortest.a -o ./relocate

clean:
	rm -rf ./relocate
