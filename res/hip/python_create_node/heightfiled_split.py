import json

node = hou.pwd()
geo = node.geometry()

# remove child by type
def removeSubChildrenOfType(node, node_type):
    for child in node.children():
        if child.type() == node_type:
            child.destroy()

# Add code to modify contents of geo.
# Use drop down menu to select examples.
rootNode = node.node('..')

# select current node
node.setDisplayFlag(True)
node.setRenderFlag(True)

# delete nodes
#removeSubChildrenOfType(rootNode, hou.sopNodeTypeCategory().nodeTypes()['heightfield_crop'])
#removeSubChildrenOfType(rootNode, hou.sopNodeTypeCategory().nodeTypes()['merge'])

# load json config file
json_path = node.parm('JsonConfigPath').eval()
json_obj  = json.load(open(json_path))

# create merge node
mergeNode = rootNode.createNode('merge')

# iterate cook regions
for idx, cook_region in enumerate(json_obj['cook_regions']):
    min_x = cook_region['min_x']
    min_y = cook_region['min_y']
    max_x = cook_region['max_x']
    max_y = cook_region['max_y']

    # crop node
    newCropNode = rootNode.createNode('heightfield_crop')
    newCropNode.setParms({
        'sizex' : max_x - min_x,
        'sizey' : max_y - min_y,
        'tx'    : (max_x + min_x) * 0.5,
        'tz'    : (max_y + min_y) * 0.5
    })

    # connect this node
    newCropNode.setInput(0, node)

    # connect merge node
    mergeNode.setInput(idx, newCropNode)

# layout
node.parent().layoutChildren()

# select merge node
mergeNode.setDisplayFlag(True)
mergeNode.setRenderFlag(True)
