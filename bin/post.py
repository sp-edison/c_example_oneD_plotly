import numpy as np
import json
from plotly.utils import PlotlyJSONEncoder
from plotly.offline import download_plotlyjs
import plotly.graph_objs as go

def plotlyfig2json(fig, fpath=None):
    redata = json.loads(json.dumps(fig.data, cls=PlotlyJSONEncoder))
    relayout = json.loads(json.dumps(fig.layout, cls=PlotlyJSONEncoder))

    fig_json=json.dumps({'data': redata,'layout': relayout})

    if fpath:
        with open(fpath, 'wb') as f:
            f.write(fig_json)
    else:
        return fig_json


	
f = open("./result/result.oneD", 'r')
lines = f.readlines()

x = [];
y = [];
for line in lines:
	if not line[0] == '#' :
		x.append( float(line.split()[0]))
		y.append( float(line.split()[1]))
#print(x,y)
f.close()

trace = go.Scatter(
    x = x,
    y = y,
    mode = 'lines')

# Edit the layout
layout = dict(title = 'Sinc plot',
              xaxis = dict(title = 'Time'),
              yaxis = dict(title = 'Amplitude'),
              )

fig = go.Figure(data=[trace], layout=layout)

plotlyfig2json(fig, './result/plot.json')
