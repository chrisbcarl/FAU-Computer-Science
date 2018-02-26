# Chris Carl
# Dr. Bou-Harb
# 2017F - CNT 4713: Computer Networking Projects
# Final Project

import pyshark
import requests 
import math
import pprint
import itertools, sys
import time
import json
from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt
import numpy as np
import string
import matplotlib.cm as cm

def pcap_analyzer(filename):
    spinner = itertools.cycle(['-', '/', '|', '\\'])
    notification_point = 50000
    pp = pprint.PrettyPrinter(indent=4)
    pcap = pyshark.FileCapture(filename)
    ips = {}
    isps = {}
    ddos_type = {}
    rate = {}
    cities = {}

    print('Analyzing packets:')
    i = 0
    j = 1
    for pkt in pcap:
        sys.stdout.write(next(spinner))
        sys.stdout.flush()
        sys.stdout.write('\b')

        time = float(pkt.sniff_timestamp)
        ms = str(math.floor(time % 1000))
        protocol =  pkt.transport_layer
        src_addr = pkt.ip.src
        dst_addr = pkt.ip.dst
        if src_addr not in ips:
            ips[src_addr] = 0
        if protocol not in ddos_type:
            ddos_type[protocol] = 0
        if ms not in rate:
            rate[ms] = 0
        ips[src_addr] += 1
        ddos_type[protocol] += 1
        rate[ms] += 1

        i += 1
        if i == notification_point:
            print(str(i * j) + ' packets analyzed...')
            i = 0
            j += 1
    print('Finally ' + str(i + j * notification_point) + ' packets analyzed...')

    # prep ips for processing
    ips_lst = [(ips[k], k) for k in ips]
    ips_lst = sorted(ips_lst, reverse=True)

    x = []
    y = []
    z = []

    for i in range(0, 100):
        ip = str(ips_lst[i][1])
        r = requests.get('http://ipinfo.io/' + ip)
        body = json.loads(r.content)
        # pp.pprint(body)
        # print(body)
        # print(ips_lst[i][0], ips_lst[i][1], body['country_name'])
        if 'loc' in body:
            location = body['loc']
        else :
            location = '0,0'

        location = location.split(',')
        x.append(float(location[1]))
        y.append(float(location[0]))
        z.append(ips_lst[i][0])

        if 'org' in body:
            isp = body['org']
        else:
            isp = 'hidden'

        if 'country' in body:
            country = body['country']
        else:
            country = 'hidden'
        
        if 'city' in body:
            city = body['city']
        else:
            city = 'hidden'

        location = city + ', ' + country
        if isp not in isps:
            isps[isp] = 0
        if location not in cities:
            cities[location] = 0
        isps[isp] += 1 * ips_lst[i][0]
        cities[location] += 1 * ips_lst[i][0]
        # map.plot(x1, y1, 'ro', markersize=c/10., alpha=0.4)

    # prep rate of attack for display
    times = len(rate)
    rate_lst = [rate[k] for k in rate]
    average = np.mean(rate_lst)

    ddos_type_lst = [(ddos_type[k], k) for k in ddos_type]
    ddos_type_lst = sorted(ddos_type_lst, reverse=True)
    isps_lst = [(isps[k], k) for k in isps]
    isps_lst = sorted(isps_lst, reverse=True)
    cities_lst = [(cities[k], k) for k in cities]
    cities_lst = sorted(cities_lst, reverse=True)
    # print(average, 'pkts / s')
    # print(ddos_type)
    # print(isps)
    # print(cities)

    suspect_location = cities_lst[0][1]
    suspect_isp = isps_lst[0][1]
    suspect_ddos = ddos_type_lst[0][1]
    suspect_ip = ips_lst[0][1]

    print('This attack is mostly likely coming from', suspect_location, \
        'and hosted by the ISP known as', suspect_isp, \
        'at a rate of', average, 'pkts / s',
        'with a DDoS type most likely of', suspect_ddos,
        'from the following ip address:', suspect_ip)

    m = Basemap(projection='mill',lon_0=-50,lat_0=60,resolution='l')

    m.drawcoastlines()
    m.drawparallels(np.arange(-90,90,30),labels=[1,0,0,0])
    m.drawmeridians(np.arange(m.lonmin,m.lonmax+30,60),labels=[0,0,0,1])
    m.drawmapboundary(fill_color='black') # fill to edge
    m.drawcountries()
    m.fillcontinents(color='white',lake_color='black',zorder=0)

    norm = np.linalg.norm(z)
    avgz = np.mean(z[25:])
    sizes = [ i / avgz for i in z]
    x1,y1=m(x,y)
    m.scatter(x1,y1,s=sizes,marker="o",cmap=cm.cool,alpha=0.7)
    title = suspect_ip + ', in ' + suspect_location
    plt.title('Attacks, suspected origin: ' + title)
    plt.show()

 
opts = {}  # Empty dictionary to store key-value pairs.
argv = sys.argv
while argv:  # While there are arguments left to parse...
    if argv[0][0] == '-':  # Found a "-name value" pair.
        opts[argv[0]] = argv[1]  # Add key and value to the dictionary.
    argv = argv[1:]  # Reduce the argument list by copying it starting from index 1

if '-file' in opts:
    pcap_analyzer(opts['-file'])
else:
    print('No file supplied')
