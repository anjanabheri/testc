    classList = preXmlData.getElementsByTagName("MOI")
    for classData in classList:
        attribList = classData.getElementsByTagName("Attribute")
        for attribute in attribList:
            attrib = attribute.getAttribute("Name")
            print("Attrib : %s \n" %(attrib))
            if (attrib == "mmeLocalVLAN1"):
                attribute.setAttribute("Name", "ANJAN")
                print("Attrib : %s \n" %(attribute.getAttribute("Name")))

    with codecs.open(options.prexml, "w", "utf-8") as out:
        preXmlData.writexml(out)

