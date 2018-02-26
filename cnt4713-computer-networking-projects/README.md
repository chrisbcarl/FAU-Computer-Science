## fau-cnt4713-2017f-ccarl2 Synopsis

Final project for Computer Networking Projects at FAU

## Setup

* Install [Anaconda](https://www.anaconda.com/download/)
* Install [Wireshark](https://www.wireshark.org)
* Install PyShark

```bash
pip install pyshark
```

* Install Basemap

```bash
conda install -c anaconda basemap 
```

* Install Requests

```bash
pip install requests
```

## Running

* (Optional) split the .pcap file into chunks using ```editcap -i <step_seconds> <input_filename> <output_filename>```
* Run script.py with the following arguments:
```bash
python script.py -file <filename.pcap>
```

## Pseudocode

```
dict = {}
for each packet in packetfile:
  ip = packet.src
  isp = packet.isp
  coordinates = packet.lat, packet.long
  location = packet.city, packet.country

  dict[ip, isp, coordinates, location] += 1

map.draw(world)
map.plot(dict[coordinates])
print('Attack coming from ')
```

## Results and Analysis

(Running from a sliced .pcap of 5 seconds)
This attack is mostly likely coming from Clarks Summit, US and hosted by the ISP known as AS46664 VolumeDrive at a rate of 1101.54545455 pkts / s with a DDoS type most likely of TCP from the following ip address: 173.242.117.189


## Relevant Matlab Documentation

* [Basemap Examples](https://matplotlib.org/basemap/users/examples.html)
* [MatplotLib Scatter](http://matplotlib.org/api/pyplot_api.html#matplotlib.pyplot.scatter)
* [Matplotlib Basemap Toolkit](http://matplotlib.org/basemap/api/basemap_api.html#mpl_toolkits.basemap.Basemap.streamplot)