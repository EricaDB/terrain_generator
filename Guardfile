guard :shell do
  watch(/(.*)bind.cpp/) do |m| 
	cclass=m[0].split('.')[0]
	cclass=cclass.split('_')[0]
	`emcc -O3 --memory-init-file 0 --bind -o js/#{cclass}.js #{cclass}_bind.cpp`
  end
end

