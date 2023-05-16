{% set cluster_members = [] -%}
{%- for node in groups[pxc_cluster_group] %}
  {%- set _ = cluster_members.append(hostvars[node]['ansible_' + hostvars[node].pxc_cluster_bind_interface].ipv4.address) -%}
{% endfor -%}
{# #}
{% set mysql_allow = [] -%}
{%- for elt in pxc_filter_allow_mysql_port %}
  {% if elt in hostvars %}
  {# this is a node #}
    {%- set _ = mysql_allow + hostvars[elt]['ansible_all_ipv4_addresses'] -%}
  {% elif elt|ipaddr %}
  {# this is an IP #}
    {%- set _ = mysql_allow.append(elt) -%}
  {% else %}
  {# this is a group #}
    {% for hst in groups[elt] %}
      {%- set _ = mysql_allow + hostvars[hst]['ansible_all_ipv4_addresses'] -%}
    {% endfor %}
  {% endif %}
{% endfor -%}
