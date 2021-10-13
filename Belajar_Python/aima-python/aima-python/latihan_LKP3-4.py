from search import *

jakarta_map = UndirectedGraph(dict(
    Merdeka_Palace=dict(Istiqlal_Mosque=10, National_Museum_of_Indonesia=20),
    Istiqlal_Mosque=dict(Gatot_Soebroto_Army_Hospital=20, Gambir_Station=15, Sarinah=35),
    Gambir_Station=dict(Gatot_Soebroto_Army_Hospital=10, Sarinah=25),
    Sarinah=dict(National_Museum_of_Indonesia=15, Hotel_Indoensia=15, Jakarta_Planetarium=25),
    Manggarai_Station=dict(Jakarta_Planetarium=40, Hotel_Indoensia=90),
    Hotel_Indoensia=dict(Jakarta_Planetarium=70, WTC_Jakarta=20, GBK=50),
    Sudirman_Central=dict(WTC_Jakarta=30, GBK=30),
    Gatot_Soebroto_Army_Hospital=dict(Jakarta_Planetarium=55)
    ))

jakarta_map.locations = dict(
    Sudirman_Central=(40, 10), GBK=(10, 20), WTC_Jakarta=(60, 20),
    Hotel_Indoensia=(50, 50), Manggarai_Station=(120, 30), Jakarta_Planetarium=(100, 55),
    Sarinah=(60, 80), National_Museum_of_Indonesia=(40, 90), Merdeka_Palace=(50, 150),
    Istiqlal_Mosque=(85, 150), Gambir_Station=(100, 100), Gatot_Soebroto_Army_Hospital=(110, 120)
)

jakarta_problem = GraphProblem('Sudirman_Central', 'Istiqlal_Mosque', jakarta_map)
# LKP3
print([node.state for node in breadth_first_graph_search(jakarta_problem).path()])
print([node.state for node in depth_first_graph_search(jakarta_problem).path()])

# LKP4 
print([node.state for node in best_first_graph_search(jakarta_problem, lambda node: node.path_cost).path()])
print([node.state for node in astar_search (jakarta_problem).path()])
