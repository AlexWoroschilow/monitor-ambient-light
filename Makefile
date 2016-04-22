all: deb

deb: clean
	sudo chown -R root:root build
	mkdir -p build/usr/bin
	mkdir -p build/usr/lib/monitor-ambient-light
	cp monitor_ambient_light build/usr/lib/monitor-ambient-light/monitor-ambient-light
	ln -rs build/usr/lib/monitor-ambient-light/monitor-ambient-light build/usr/bin/monitor-ambient-light
	find build -type d -exec chmod 0755 {} \;
	find build -type f -exec chmod 0644 {} \;
	sudo chmod +x build/usr/lib/monitor-ambient-light/monitor-ambient-light
	sudo chmod -R +x build/etc/monitor-ambient-light/update.d
	./dpkg-deb-nodot build monitor-ambient-light
	sudo chown -R sensey:sensey build

clean:
	rm -rf build/usr/bin
	rm -rf build/usr/lib/monitor-ambient-light
